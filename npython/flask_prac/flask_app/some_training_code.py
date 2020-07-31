#!/usr/bin/env python3

'''flask demo'''

from datetime import datetime
from flask import Flask
from flask import render_template
from flask_sqlalchemy import SQLAlchemy

# flask app
app = Flask(__name__)

# where database is going to be stored
# /// is relative to this file, while //// is abs
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///posts.db'
datab = SQLAlchemy(app)


class BlogPost(datab.Model):
    '''class for blog post'''
    # each row is seperate blog post, is column is different class variable
    __tablename__ = 'BlogPost Table'  # necessary to use model
    id = datab.Column(datab.Integer, primary_key=True)
    title = datab.Column(datab.String(128), nullable=False)
    content = datab.Column(datab.Text, nullable=False)
    author = datab.Column(datab.String(32), nullable=True, default='N/A')
    data_posted = datab.Column(datab.DateTime, nullable=False,
                               default=datetime.utcnow)

    # returns a printable representation of an object
    def __repr__(self):
        return 'Blog post ' + str(self.id)


# url route (decorator)
@app.route('/')  # base url(domain)
@app.route('/home')  # using multiple route
# whatever functions comes next linearly will get run after the
# deocrator above
def hello():
    '''return hello'''
    return "Hello World 2"


@app.route('/college')
def hello_again():
    '''next time hello'''
    return "Hello to the college"


# path(<datatype:variable_name>)
# you can do int etc.
@app.route("/home/<string:name>")
def hello_man(name):
    return "Hello " + name


# multiple(dynamic urls)
@app.route("/home/user/<string:name>/posts/<int:id_num>")
def with_username(name, id_num):
    return "Hello, " + name + ". Your ID is " + str(id_num)


# http request you want to use, pass list of the allowed methods
@app.route('/onlyget', methods=['POST'])
def get_req_get():
    # this will give 'Method Not Allowed'
    return "You can only get this webpage. POST"


@app.route('/template')
def index():
    return """
<h1>Template Page</h1>
<b><i><u>This is a small sample for running html</u></i></b>
    """


@app.route('/template/index')
def index_temp():
    '''sourcing template from outside'''
    return render_template('index.html')


all_posts = [
    {
        'title': 'Post 1',
        'content': 'This is the content of Post 1, How Dare You!',
        'writer': 'Abhay'
    },
    {
        'title': 'Post 2',
        'content': 'This is the content of Post 2, LaLaLaLaLaLaLa',
    }
]


@app.route('/wall/posts')
def posts_on_wall():
    return render_template('wall_posts.html', posts=all_posts)


if __name__ == "__main__":
    app.run(debug=True)  # full breakdown of error
