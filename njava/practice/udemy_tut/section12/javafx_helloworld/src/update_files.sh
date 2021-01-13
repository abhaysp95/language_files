#!/usr/bin/env bash

rsync /opt/SceneBuilder/app/javafx_helloworld.fxml ~/Documents/njava/practice/udemy_tut/section12/javafx_helloworld/src/com/javafx_demo/helloworld
rsync /opt/SceneBuilder/app/javafx_helloworld.fxml ~/Documents/njava/practice/udemy_tut/section12/javafx_helloworld/bin/com.javafx_demo.helloworld/com/javafx_demo/helloworld

rsync ~/Documents/njava/practice/udemy_tut/section12/javafx_helloworld/src/com/javafx_demo/helloworld/javafx_helloworld.fxml /opt/SceneBuilder/app
rsync ~/Documents/njava/practice/udemy_tut/section12/javafx_helloworld/src/com/javafx_demo/helloworld/javafx_helloworld.fxml ~/Documents/njava/practice/udemy_tut/section12/javafx_helloworld/bin/com.javafx_demo.helloworld/com/javafx_demo/helloworld
