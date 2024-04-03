import QtQuick
import QtQuick.Controls

Item{
    width: 1920
    height: 1080

    Rectangle {
        id: backgroundcover
        anchors.fill: parent
        color:"black"
    }

    Image {
        id: background
        anchors.fill: parent
        source: "./media/background.png"
        opacity: 0.5
        asynchronous: true
    }



    SwipeView {
        id: view

        anchors.fill: parent

        Burgerslistpage{
            id: firstPage
        }

        Shoppingcartpage {
            id: secondPage
        }

    }
}

