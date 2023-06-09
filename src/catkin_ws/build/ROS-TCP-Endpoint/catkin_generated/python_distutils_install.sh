#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/poskuka-nearlab/catkin_ws/src/ROS-TCP-Endpoint"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/poskuka-nearlab/catkin_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/poskuka-nearlab/catkin_ws/install/lib/python2.7/dist-packages:/home/poskuka-nearlab/catkin_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/poskuka-nearlab/catkin_ws/build" \
    "/usr/bin/python2" \
    "/home/poskuka-nearlab/catkin_ws/src/ROS-TCP-Endpoint/setup.py" \
    egg_info --egg-base /home/poskuka-nearlab/catkin_ws/build/ROS-TCP-Endpoint \
    build --build-base "/home/poskuka-nearlab/catkin_ws/build/ROS-TCP-Endpoint" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/poskuka-nearlab/catkin_ws/install" --install-scripts="/home/poskuka-nearlab/catkin_ws/install/bin"
