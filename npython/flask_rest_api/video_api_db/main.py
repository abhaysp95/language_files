#!/usr/bin/env python3 ''' using rest api with database '''

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
        return f"Video(id: {self.id}, name: {self.name}, views: {self.views}, likes: {self.likes})"


# database.create_all()  # do this first time
# or create database using interpretor

# makes sure that request is passed and parsed
video_put_args = reqparse.RequestParser()
video_put_args.add_argument("name", type=str, help="Name of video is required", required=True)
video_put_args.add_argument("views", type=int, help="Views of video is required", required=True)
video_put_args.add_argument("likes", type=int, help="Likes of video is required", required=True)

video_update_args = reqparse.RequestParser()
video_update_args.add_argument("name", type=str, help="Name of video is required")
video_update_args.add_argument("views", type=int, help="Views of video is required")
video_update_args.add_argument("likes", type=int, help="Likes of video is required")


# for json serialization
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
        result = VideoModel.query.filter_by(id=video_id).first()
        if not result:
            abort(404, message="Video couln't be found with this id...")
        return result  # returns object of instance of VideoModel

    @marshal_with(resource_fields)
    def put(self, video_id):
        '''make a new object in database'''
        args = video_put_args.parse_args()
        result = VideoModel.query.filter_by(id=video_id).first()
        if result:
            abort(409, message="Video id already exist...")
        video = VideoModel(
            id=video_id,
            name = args['name'],
            views = args['views'],
            likes = args['likes']
        )
        database.session.add(video)  # temporary adding
        database.session.commit()  # making permanent
        return video, 201

    @marshal_with(resource_fields)
    def patch(self, video_id):
        '''udpates for the video'''
        args = video_update_args.parse_args()
        result = VideoModel.query.filter_by(id=video_id).first()
        if not result:
            abort(404, message="Can't Update, Video doesn't exist")
        # elements are already in args, cause reqparse make them None if not given
        # so, the values are not None
        if args["name"]:
            result.name = args["name"]
        if args["views"]:
            result.views = args["views"]
        if args["likes"]:
            result.likes = args["likes"]

        # video already in db, so no need to add again, just commit
        database.session.commit()
        return result, 201

    def delete(self, video_id):
        '''delete the given video'''
        result = VideoModel.query.filter_by(id=video_id)
        if not result:
            abort(404, message="Can't delete, Video doesn't exist")
        result.delete()
        database.session.commit()
        return "Video Deleted", 204


api.add_resource(Video, "/video/<int:video_id>")


if __name__ == "__main__":
    app.run(debug=True)
