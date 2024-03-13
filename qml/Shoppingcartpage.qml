import QtQuick 2.15

Item {
    id: main
    width: 800
    height: 600

    property string nameBurger : ""

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
            style: Text.Outline;
            styleColor: "black"
        }

        Text {
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 50
            anchors.right: parent.right
            anchors.rightMargin: 50
            text: m_cart.sum
            font.family: "HelveticaS"
            font.pointSize: 80
            color: "white"
            style: Text.Outline;
            styleColor: "black"
        }

        Rectangle{
            id: buybutton
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 40
            anchors.horizontalCenter: parent.horizontalCenter
            width: 180
            height: 40
            border.color: "black"
            border.width: 5
            radius: 15

            Text {
                anchors.centerIn: parent
                text: "remove from cart"
                font.family: "roboto"
                font.pointSize: 10
                color: "black"
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(chartlist.currentIndex !== -1){
                        if(main.nameBurger !== "" ){
                            m_cart.remove(main.nameBurger,chartlist.currentIndex)
                        }
                    }
                }
            }
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
            model: m_cart
            delegate: contactsDelegate
            focus: true


            Component {
                id: contactsDelegate

                Rectangle {
                    id: wrapper
                    width: 400
                    height: contactInfo.height

                    color: ListView.isCurrentItem ? "gray" : "white"
                    property var burgername : namerole

                    Text {
                        id: contactInfo
                        text: burgername
                        color: wrapper.ListView.isCurrentItem ? "black" : "black"

                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                chartlist.currentIndex = index
                                main.nameBurger = burgername
                            }
                        }
                    }
                }
            }

            onCurrentIndexChanged: {
                main.nameBurger = itemAtIndex(chartlist.currentIndex).burgername
            }
        }
    }
}
