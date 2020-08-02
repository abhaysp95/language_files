#!/usr/bin/env python3

'''
using rest api with database
'''

from flask import Flask
from flask import request
from flask_restful import Api
from flask_restful import Resource
from flask_restful import reqparse
from flask_restful import abort
from flask_restful import fields
from flask_restful import marshal_with
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
api = Api(app)
app.config['SQLALCHEMY_DATABASE_URI'] = "sqlite:///database.db"
database = SQLAlchemy(app)


class VideoModel(database.Model):
    '''create Model for database'''
    id = database.Column(database.Integer, primary_key=True)
    name = database.Column(database.String(128), nullable=False)
    views = database.Column(database.Integer, nullable=False)
    likes = database.Column(database.Integer, nullable=False)

    def __repr__(self):
        return f"Video(name = {name}, views = {views}, likes = {likes})"


video_put_args = reqparse.RequestParser()
video_put_args.add_argument("name", type=str, help="Name of video is required", required=True)
video_put_args.add_argument("views", type=int, help="Views of video is required", required=True)
video_put_args.add_argument("likes", type=int, help="Likes of video is required", required=True)


resource_fields = {
    'id': fields.Integer,
    'name': fields.String,
    'views': fields.Integer,
    'likes': fields.Integer
}


class Video(Resource):
    '''resource class'''

    # takes return and serializes using resource_fields
    @marshal_with(resource_fields)
    def get(self, video_id):
        result = VideoModel.query.get(id=video_id)
        return result  # returns object of instance of VideoModel

    @marshal_with(resource_fields)
    def put(self, video_id):
        '''make a new object in database'''
        args = video_put_args.parse_args()
        video = VideoModel(
            id=video_id,
            name = args['name'],
            views = args['views'],
            likes = args['likes']
        )
        database.session.add(video)  # temporary adding
        database.session.commit()  # making permanent
        return video, 201


api.add_resource(Video, "/video/<int:video_id>")


if __name__ == "__main__":
    app.run(debug=True)
