#!/usr/bin/env bash

# file: javafx_events.fxml
# source: /opt/SceneBuilder/app
# desitination: src and bin(module)
rsync -av /opt/SceneBuilder/app/javafx_events.fxml /home/raytracer/Documents/njava/practice/udemy_tut/section12/javafx_events/src/com/javafx_demo/events
rsync -av /opt/SceneBuilder/app/javafx_events.fxml /home/raytracer/Documents/njava/practice/udemy_tut/section12/javafx_events/bin/com.javafx_demo.events/com/javafx_demo/events

# file: javafx_events.fxml
# source: src
# desitnation: scenebuilder pos. and bin(module)
rsync -a /home/raytracer/Documents/njava/practice/udemy_tut/section12/javafx_events/src/com/javafx_demo/events/javafx_events.fxml /opt/SceneBuilder/app
rsync -a /home/raytracer/Documents/njava/practice/udemy_tut/section12/javafx_events/src/com/javafx_demo/events/javafx_events.fxml /home/raytracer/Documents/njava/practice/udemy_tut/section12/javafx_events/bin/com.javafx_demo.events/com/javafx_demo/events

# provide further sync details here