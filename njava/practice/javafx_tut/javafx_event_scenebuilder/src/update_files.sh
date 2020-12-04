#!/usr/bin/bash

#/usr/bin/cp -v /opt/SceneBuilder/app/javafx_event.fxml ~/Documents/njava/practice/javafx_tut/javafx_event_scenebuilder/src/com/javafx_event

#/usr/bin/cp -v ~/Documents/njava/practice/javafx_tut/javafx_event_scenebuilder/src/com/javafx_event/application.css ~/Documents/njava/practice/javafx_tut/javafx_event_scenebuilder/bin/com.javafx_event/com/javafx_event

#/usr/bin/cp -v ~/Documents/njava/practice/javafx_tut/javafx_event_scenebuilder/src/com/javafx_event/javafx_event.fxml ~/Documents/njava/practice/javafx_tut/javafx_event_scenebuilder/bin/com.javafx_event/com/javafx_event

rsync -au /opt/SceneBuilder/app/javafx_event.fxml ~/Documents/njava/practice/javafx_tut/javafx_event_scenebuilder/src/com/javafx_event
rsync -au /opt/SceneBuilder/app/javafx_event.fxml ~/Documents/njava/practice/javafx_tut/javafx_event_scenebuilder/bin/com.javafx_event/com/javafx_event

rsync -au ~/Documents/njava/practice/javafx_tut/javafx_event_scenebuilder/src/com/javafx_event/javafx_event.fxml /opt/SceneBuilder/app
rsync -au ~/Documents/njava/practice/javafx_tut/javafx_event_scenebuilder/src/com/javafx_event/javafx_event.fxml ~/Documents/njava/practice/javafx_tut/javafx_event_scenebuilder/bin/com.javafx_event/com/javafx_event

rsync -au ~/Documents/njava/practice/javafx_tut/javafx_event_scenebuilder/src/com/javafx_event/application.css ~/Documents/njava/practice/javafx_tut/javafx_event_scenebuilder/bin/com.javafx_event/com/javafx_event
