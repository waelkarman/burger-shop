## Burger Shop App [deferred]

Just for fun ! This app is integrated in [bunch-linux](https://github.com/waelkarman/bunch-linux-manifests) project.


<img src="doc/screen.gif">

- SQLite
- C++/17
- Qt6
- QML
- Cmake


# Build and run
please run: 
> cmake . ; make; ./burger-shop

# Build and check code issue with SonarQube
replace the token in "sonar-project.properties" and build using "build.sh" to enable SonarQube Code Analysis 

then run: 
> sonar-scanner 
to perform the analysis 
