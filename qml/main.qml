import QtQuick
import QtQuick.Controls

Item{
    width: 800
    height: 600

    SwipeView {
        id: view

        currentIndex: 0
        anchors.fill: parent

        Bookslistpage{
            id: firstPage

            Image {
                id: bookcover
                height: 270
                width: 210
                anchors.right: parent.right
                anchors.rightMargin: 90
                anchors.top: parent.top
                anchors.topMargin: 195
                source: ""
                asynchronous: true
                smooth: true
                opacity: 1

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        view.currentIndex = view.currentIndex+1
                    }
                }
            }
        }

        Shoppingcartpage {
            id: secondPage
        }

    }
}

