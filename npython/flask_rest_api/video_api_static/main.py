#!/usr/bin/env python3

'''
demo video api with REST
'''

from flask import Flask, request
from flask_restful import Api, Resource, reqparse, abort

app = Flask(__name__)
api = Api(app)

video_put_args = reqparse.RequestParser()
video_put_args.add_argument("Name", type=str,
                            help="Name of the video is required",
                            required=True)
video_put_args.add_argument("Views", type=int,
                            help="Views of the video is required",
                            required=True)
video_put_args.add_argument("Likes", type=int,
                            help="Likes on the video is required",
                            required=True)

videos: dict = {}


def abort_if_video_id_not_found(video_id):
    '''do not crash, just abort'''
    if video_id not in videos:
        # status code, message
        abort(404, message="Could not find video...")


def abort_if_video_exists(video_id):
    '''abort if video exists'''
    if video_id in videos:
        abort(409, message="Video already exists...")


class Video(Resource):
    '''related to video api'''

    # what get method should do
    def get(self, video_id):
        '''get video'''
        abort_if_video_id_not_found(video_id)
        return videos[video_id]

    # what put method should do
    def put(self, video_id):
        '''put video'''
        # don't create video that already exists
        abort_if_video_exists(video_id)

        args = video_put_args.parse_args()

        # if successfully got the args, then store
        videos[video_id] = args

        # print(request.form['likes'])
        # return {video_id: args}

        return videos[video_id], 201  # status code 201 = worked

    def delete(self, video_id):
        '''delete the video'''
        abort_if_video_id_not_found(video_id)
        del videos[video_id]
        return '', 204  # deleteion successful


api.add_resource(Video, "/video/<int:video_id>")


if __name__ == "__main__":
    app.run(debug=True)
