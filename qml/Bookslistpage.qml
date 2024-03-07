import QtQuick
import QtQuick.Controls

Item {
    width: 800
    height: 600

    Rectangle {
        id: root
        anchors.fill: parent
        color: "white"

        Image {
            id: background
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
        }

        Text {
            anchors.top: parent.top
            anchors.topMargin: 50
            anchors.left: parent.left
            anchors.leftMargin: 50
            text: "Book Shop"
            font.family: "HelveticaS"
            font.pointSize: 24
            color: "black"
        }

        Component {
            id: delegate

            Column {
                id: wrapper
                opacity: PathView.isCurrentItem ? 1 : 0.6
                property var bookname : namerole
                property var bookprice : pricerole
                property var bookbackground : backgroundrole

                Image {
                    anchors.horizontalCenter: nameText.horizontalCenter
                    width: 64; height: 64
                    source: "./media/book.png"

                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            console.log("price of : ",bookname)
                        }
                    }
                }

                Text {
                    id: nameText
                    text: bookname
                    font.pointSize: 10
                }

                Text {
                    id: priceText
                    text: bookprice+" €"
                    font.pointSize: 8
                }
            }
        }

        PathView {
            property var model_name: m_shop

            id: bookpath
            anchors.centerIn: parent
            anchors.fill: parent
            model: model_name
            delegate: delegate
            path: Path {
                startX: root.width/9; startY: root.height-root.height/3
                PathQuad { x: root.width+root.width/10; y: root.height/10; controlX: root.width/5; controlY: root.height/6 }
            }

            onCurrentIndexChanged: {
                currentbook.text = itemAtIndex(currentIndex).bookname
                background.source = itemAtIndex(currentIndex).bookbackground
            }
        }


        Text {
            id: currentbook
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 50
            anchors.right: parent.right
            anchors.rightMargin: 50
            text: ""
            font.family: "HelveticaS"
            font.pointSize: 24
            color: "black"
        }
    }
}
