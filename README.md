## DM Embedded World Presentation Demo [in development]

<img src="doc/screen.gif">

- SQLite
- C++/17
- Qt6
- QML
- Cmake


# Build :
please source the environment to build for target: 
> cmake . ; make; 


# Run the app within weston environment:

> export WAYLAND_DISPLAY=wayland-1<br>
> export XDG_RUNTIME_DIR=/run/user/1000<br>
> export QT_QPA_PLATFORM=wayland<br>
> LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./cart:./shop:./KoDInput:./burger:./dbhelper:./sqlite ./burger-shop


