#!/usr/bin/env python3

'''
demo REST api
'''

from flask import Flask
from flask_restful import Api, Resource

app = Flask(__name__)
api = Api(app)  # wrap the app in api

names = {
    "myname": {
        "age": 20, "gender": "male"
    },
    "yourname": {
        "age": 23, "gender": "female"
    }
}


class HelloWorld(Resource):
    '''hello world resource class'''

    # override, handle get method
    def get(self, name, test):
        # everytime we want to return some type of information from our
        # api, we need to make sure that information is serialable
        return {
            "data": "Hello World from get method",
            "name": names[name],
            "test": test
        }

    # override, post method
    def post(self):
        return {"data": "Hello World from post method"}


# register as Resource
api.add_resource(HelloWorld, "/helloworld/<string:name>/<int:test>")


if __name__ == "__main__":
    app.run(debug=True)
