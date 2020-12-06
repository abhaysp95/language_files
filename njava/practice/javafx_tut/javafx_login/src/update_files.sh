#!/usr/bin/bash

# javafx_main.fxml
# source -> opt/SceneBuilder/app
# destination -> src/package
rsync -au /opt/SceneBuilder/app/javafx_main.fxml ~/Documents/njava/practice/javafx_tut/javafx_login/src/com/javafx_demo/login
# javafx_main.fxml
# source -> opt/SceneBuilder/app
# destination -> bin/module_path/package
rsync -au /opt/SceneBuilder/app/javafx_main.fxml ~/Documents/njava/practice/javafx_tut/javafx_login/bin/com.javafx_demo.login/com/javafx_demo/login

# javafx_login.fxml
# source -> /opt/SceneBuilder/app
# destination -> src/package
rsync -au /opt/SceneBuilder/app/javafx_login.fxml ~/Documents/njava/practice/javafx_tut/javafx_login/src/com/javafx_demo/login
# javafx_login.fxml
# source -> /opt/SceneBuilder/app
# destination -> bin/module_path/package
rsync -au /opt/SceneBuilder/app/javafx_login.fxml ~/Documents/njava/practice/javafx_tut/javafx_login/bin/com.javafx_demo.login/com/javafx_demo/login


# javafx_main.fxml
# source -> src/package
# destination -> /opt/SceneBuilder/app
rsync -au ~/Documents/njava/practice/javafx_tut/javafx_login/src/com/javafx_demo/login/javafx_main.fxml /opt/SceneBuilder/app
# javafx_main.fxml
# source -> src/package
# destination -> bin/module_path/package
rsync -au ~/Documents/njava/practice/javafx_tut/javafx_login/src/com/javafx_demo/login/javafx_main.fxml ~/Documents/njava/practice/javafx_tut/javafx_login/bin/com.javafx_demo.login/com/javafx_demo/login

# javafx_login.fxml
# source -> src/package
# destination -> /opt/SceneBuilder/app
rsync -au ~/Documents/njava/practice/javafx_tut/javafx_login/src/com/javafx_demo/login/javafx_login.fxml /opt/SceneBuilder/app

# javafx_login.fxml
# source -> src/package
# destination -> bin/module_path/package
rsync -au ~/Documents/njava/practice/javafx_tut/javafx_login/src/com/javafx_demo/login/javafx_login.fxml ~/Documents/njava/practice/javafx_tut/javafx_login/bin/com.javafx_demo.login/com/javafx_demo/login

# javafx_application.css
# source -> src/package
# destination -> bin/module_path/package
rsync -au ~/Documents/njava/practice/javafx_tut/javafx_login/src/com/javafx_demo/login/javafx_application.css ~/Documents/njava/practice/javafx_tut/javafx_login/bin/com.javafx_demo.login/com/javafx_demo/login
