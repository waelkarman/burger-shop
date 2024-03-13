import QtQuick
import QtQuick.Controls

Item{
    width: 800
    height: 600

    SwipeView {
        id: view

        currentIndex: 0
        anchors.fill: parent

        Burgerslistpage{
            id: firstPage

            Image {
                id: burgercover
                height: 270
                width: 210
                anchors.right: parent.right
                anchors.rightMargin: 90
                anchors.top: parent.top
                anchors.topMargin: 195
                asynchronous: true
                smooth: true
                opacity: 1

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        //view.currentIndex = view.currentIndex+1
                    }
                }
            }

            Text {
                id: currentburger
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 260
                anchors.right: burgercover.left
                anchors.rightMargin: 20
                font.family: "HelveticaS"
                font.pointSize: 24
                color: "white"
                style: Text.Outline;
                styleColor: "black"
            }

            Text {
                id: currentprice
                anchors.top: currentburger.bottom
                anchors.topMargin: 15
                anchors.right: burgercover.left
                anchors.rightMargin: 20
                font.family: "HelveticaS"
                font.pointSize: 16
                color: "white"
                style: Text.Outline;
                styleColor: "black"
            }

            Rectangle{
                id: buybutton
                anchors.top: burgercover.bottom
                anchors.topMargin: 20
                anchors.horizontalCenter: burgercover.horizontalCenter
                width: 180
                height: 40
                border.color: "black"
                border.width: 5
                radius: 15

                Text {
                    anchors.centerIn: parent
                    text: "add to cart"
                    font.family: "roboto"
                    font.pointSize: 15
                    color: "black"
                }

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        m_cart.add(currentburger.text)
                    }
                }
            }
        }

        Shoppingcartpage {
            id: secondPage
        }

    }
}

