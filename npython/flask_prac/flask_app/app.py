#!/usr/bin/env python3

'''
make a demo app with flask
'''

from datetime import datetime
from flask import Flask
from flask import request
from flask import redirect
from flask import render_template
from flask_sqlalchemy import SQLAlchemy

# flask app
app = Flask(__name__)

# storing database(relative path to this file)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///posts.db'
database = SQLAlchemy(app)


class BlogPost(database.Model):
    '''creating model for database storage'''
    # each row is seperate BlogPost
    # each column is different class variable
    __tablename__ = 'BlogPost Table'
    id = database.Column(database.Integer, primary_key=True)
    title = database.Column(database.String(128), nullable=False)
    content = database.Column(database.Text, nullable=False)
    author = database.Column(database.String(32), nullable=True, default='N/A')
    # this isn't correct timing to work with date_posted, and last_edit
    __current_time__ = datetime.now()
    date_posted = database.Column(database.DateTime,
                                  nullable=False,
                                  default=__current_time__)
    last_edit = database.Column(database.DateTime,
                                nullable=False,
                                default=__current_time__)

    # make use of this in wall_posts.html
    def return_last_edit(self):
        '''return the last edit'''
        last_edited = BlogPost.last_edit
        return last_edited

    def __repr__(self):
        return 'Blog Post ' + str(self.id)


# some dummy data
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


@app.route('/')
def root():
    '''root page'''
    return render_template('index.html')


# if not mentioned, the only allowed request by defualt is GET
@app.route('/posts', methods=['GET', 'POST'])
def posts_func():
    '''some small posting'''

    # save to database
    if request.method == 'POST':
        post_title = request.form['title']
        post_content = request.form['content']
        post_author = request.form['auth']
        new_post = BlogPost(title=post_title,
                            content=post_content,
                            author=post_author)
        database.session.add(new_post)
        database.session.commit()  # permanent save
        return redirect('/posts')  # redirect back to same session
    else:
        # redifine all posts to show from database, instead of dummy data
        all_posts = BlogPost.query.order_by(
            BlogPost.date_posted.desc()).all()  # get the saved data
    return render_template('wall_posts.html', posts=all_posts)


@app.route('/posts/new')
def new_post():
    '''create new wall post'''

    if request.method == 'POST':
        post_title = request.form['title']
        post_content = request.form['content']
        post_author = request.form['auth']
        new_post_is = BlogPost(title=post_title,
                               content=post_content,
                               author=post_author)
        database.session.add(new_post_is)
        database.session.commit()  # permanent save
        return redirect('/posts')
    else:
        return render_template('new_post.html')


@app.route('/posts/delete/<int:id_num>')
def delete_with_id(id_num):
    '''delete the blog post with id'''
    # get post to delete
    post = BlogPost.query.get_or_404(id_num)
    database.session.delete(post)  # delete the post
    database.session.commit()  # commit the changes to database
    return redirect('/posts')  # redirect back to /posts


@app.route('/posts/edit/<int:id_num>', methods=['GET', 'POST'])
def edit_with_id(id_num):
    '''edit the elements of row of BlogPost with id'''
    # if not found, 404
    post = BlogPost.query.get_or_404(id_num)
    if request.method == 'POST':
        post.title = request.form['title']
        post.content = request.form['content']
        post.author = request.form['auth']
        post.last_edit = datetime.now()
        database.session.commit()
        return redirect('/posts')
    else:
        return render_template('edit.html', post_edit=post)


if __name__ == "__main__":
    app.run(debug=True)
