#!/usr/bin/bash

# javafx_combobox.fxml
# source -> opt/SceneBuilder/app
# destination -> src/package
rsync -au /opt/SceneBuilder/app/javafx_combobox.fxml ~/Documents/njava/practice/javafx_tut/javafx_combobox/src/com/javafx_demo/combobox
# javafx_combobox.fxml
# source -> opt/SceneBuilder/app
# destination -> bin/module_path/package
rsync -au /opt/SceneBuilder/app/javafx_combobox.fxml ~/Documents/njava/practice/javafx_tut/javafx_combobox/bin/com.javafx_demo.combobox/com/javafx_demo/combobox


# javafx_combobox.fxml
# source -> src/package
# destination -> /opt/SceneBuilder/app
rsync -au ~/Documents/njava/practice/javafx_tut/javafx_combobox/src/com/javafx_demo/combobox/javafx_combobox.fxml /opt/SceneBuilder/app
# javafx_combobox.fxml
# source -> src/package
# destination -> bin/module_path/package
rsync -au ~/Documents/njava/practice/javafx_tut/javafx_combobox/src/com/javafx_demo/combobox/javafx_combobox.fxml ~/Documents/njava/practice/javafx_tut/javafx_combobox/bin/com.javafx_demo.combobox/com/javafx_demo/combobox
