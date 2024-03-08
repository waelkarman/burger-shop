import QtQuick 2.15

Item {
    width: 800
    height: 600

    Rectangle{
        id: root
        anchors.fill: parent
        color: "black"

        Image {
            id: background1
            anchors.fill: parent
            source: "./media/background1.jpg"
            opacity: 0.3
        }

        Text {
            anchors.top: parent.top
            anchors.topMargin: 50
            anchors.left: parent.left
            anchors.leftMargin: 50
            text: "Shopping Cart"
            font.family: "HelveticaS"
            font.pointSize: 24
            color: "white"
        }

        ListView {
            id: chartlist
            width: 400
            height: 100
            anchors.top: parent.top
            anchors.topMargin: 300
            anchors.horizontalCenter: parent.horizontalCenter
            orientation: ListView.Vertical
            clip: false
            model: m_shop
            delegate: contactsDelegate
            focus: true


            Component {
                id: contactsDelegate
                Rectangle {
                    id: wrapper
                    width: 400
                    height: contactInfo.height

                    color: ListView.isCurrentItem ? "gray" : "white"
                    property var bookname : namerole
                    property var bookprice : pricerole
                    property var bookbackground : backgroundrole

                    Text {
                        id: contactInfo
                        text: bookname
                        color: wrapper.ListView.isCurrentItem ? "black" : "black"

                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                chartlist.currentIndex = index
                            }
                        }
                    }
                }
            }
        }
    }
}
