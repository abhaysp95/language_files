#!/usr/bin/bash

#/usr/bin/cp -v /opt/SceneBuilder/app/javafx_calculator.fxml ~/Documents/njava/practice/javafx_tut/javafx_calculator/src/com/javafx_calculator

#/usr/bin/cp -v ~/Documents/njava/practice/javafx_tut/javafx_calculator/src/com/javafx_calculator/application.css ~/Documents/njava/practice/javafx_tut/javafx_calculator/bin/com.javafx_calculator/com/javafx_calculator

#/usr/bin/cp -v ~/Documents/njava/practice/javafx_tut/javafx_calculator/src/com/javafx_calculator/javafx_calculator.fxml ~/Documents/njava/practice/javafx_tut/javafx_calculator/bin/com.javafx_calculator/com/javafx_calculator

rsync -au /opt/SceneBuilder/app/javafx_calculator.fxml ~/Documents/njava/practice/javafx_tut/javafx_calculator/src/com/javafx_demo/calculator
rsync -au /opt/SceneBuilder/app/javafx_calculator.fxml ~/Documents/njava/practice/javafx_tut/javafx_calculator/bin/com.javafx_demo.calculator/com/javafx_demo/calculator

rsync -au ~/Documents/njava/practice/javafx_tut/javafx_calculator/src/com/javafx_demo/calculator/javafx_calculator.fxml /opt/SceneBuilder/app
rsync -au ~/Documents/njava/practice/javafx_tut/javafx_calculator/src/com/javafx_demo/calculator/javafx_calculator.fxml ~/Documents/njava/practice/javafx_tut/javafx_calculator/bin/com.javafx_demo.calculator/com/javafx_demo/calculator

#rsync -au ~/Documents/njava/practice/javafx_tut/javafx_calculator/src/com/javafx_demo/calculator/application.css ~/Documents/njava/practice/javafx_tut/javafx_calculator/bin/com.javafx_demo.calculator/com/javafx_demo/calculator
