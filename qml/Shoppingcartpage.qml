import QtQuick 2.15

Item {
    id: main
    width: 1920
    height: 1080

    property string nameBurger : ""

    Rectangle{
        id: root
        anchors.fill: parent
        color:"transparent"

        Text {
            anchors.top: parent.top
            anchors.topMargin: 50
            anchors.left: parent.left
            anchors.leftMargin: 50
            text: "Shopping Cart"
            font.family: "HelveticaS"
            font.pointSize: 24
            font.bold: true
            color: "#a8ea25"
            style: Text.Outline;
            styleColor: "black"
        }

        Text {
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 50
            anchors.right: parent.right
            anchors.rightMargin: 50
            text: m_cart.sum + "€"
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
            anchors.horizontalCenter: chartlist.horizontalCenter
            width: 180
            height: 40
            border.color: "black"
            border.width: 5
            radius: 15

            Text {
                id: buttontextremove
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
                        m_cart.remove(main.nameBurger,chartlist.currentIndex)
                    }
                }

                onPressed: {
                    buybutton.color = "black"
                    buybutton.border.color = "white"
                    buttontextremove.color = "white"
                }
                onReleased: {
                    buybutton.color = "white"
                    buybutton.border.color = "black"
                    buttontextremove.color = "black"
                }
            }
        }

        ListView {
            id: chartlist
            width: root.width
            height: root.height
            anchors.top: parent.top
            anchors.topMargin: 200
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 280
            anchors.left: parent.left
            anchors.leftMargin: 30
            orientation: ListView.Vertical
            clip: false
            model: m_cart
            delegate: contactsDelegate
            focus: true


            Component {
                id: contactsDelegate

                Rectangle {
                    id: wrapper

                    height: entryimage.height + 10
                    width: 4 + entryimage.width + 5 + entryInfo.width + 5 + entrypriceInfo.width + 10
                    opacity: ListView.isCurrentItem ? 1 : 0.7
                    border.color: ListView.isCurrentItem ? "#a8ea25" : "transparent"
                    border.width: 3
                    color: ListView.isCurrentItem ? "black" : "transparent"
                    property var burgername : namerole
                    property var burgerprice : pricerole


                    Image {
                        id: entryimage
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.leftMargin: 4
                        asynchronous: true
                        opacity: 1
                        source: "./media/l0.png"
                    }

                    Text {
                        id: entryInfo
                        anchors.left: entryimage.right
                        anchors.leftMargin: 5
                        anchors.verticalCenter: entryimage.verticalCenter
                        text: burgername + ",  "
                        font.pointSize: 30
                        color: wrapper.ListView.isCurrentItem ? "#a8ea25" : "#a8ea25"
                    }

                    Text {
                        id: entrypriceInfo
                        text: burgerprice + "€"
                        font.pointSize: 30
                        color: wrapper.ListView.isCurrentItem ? "#a8ea25" : "#a8ea25"
                        anchors.left: entryInfo.right
                        anchors.leftMargin: 5
                        anchors.verticalCenter: entryimage.verticalCenter
                    }


                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            chartlist.currentIndex = index
                            main.nameBurger = m_cart.fetchById(chartlist.currentIndex)
                        }
                    }

                }
            }

            Connections {
                target: m_cart
                function onSumChanged() {
                    if(chartlist.count>0 && chartlist.currentIndex >= 0 && chartlist.currentIndex < chartlist.count ){
                        main.nameBurger = m_cart.fetchById(chartlist.currentIndex)
                    }
                }
            }

            onCurrentIndexChanged: {
                if(chartlist.currentIndex !== -1){
                    main.nameBurger = m_cart.fetchById(chartlist.currentIndex)
                }
            }
        }
    }
}



