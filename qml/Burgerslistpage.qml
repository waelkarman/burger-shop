import QtQuick
import QtQuick.Controls
import QtQml

Item {
    id:main
    width: 1920
    height: 1080
    property int currentpriceBurger : 0

    Rectangle {
        id: root
        anchors.fill: parent
        color:"transparent"

        Text {
            id: currentprice
            anchors.top: currentburger.bottom
            anchors.topMargin: 15
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "HelveticaS"
            font.pointSize: 16
            color: "black"
            style: Text.Outline;
            styleColor: "white"
        }

        Text {
            id: currentburger
            anchors.top: burgercover.bottom
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "HelveticaS"
            font.pointSize: 24
            color: "black"
            style: Text.Outline;
            styleColor: "white"
        }

        Image {
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
            source: "./media/logo.jpeg"
            asynchronous: true
            smooth: true
            opacity: 1
            scale: 0.8
        }

        Component {
            id: delegate

            Column {
                id: wrapper
                opacity: PathView.isCurrentItem ? 1 : 0.7
                scale: PathView.isCurrentItem ? 1 : 0.5
                property var burgername : namerole
                property var burgerprice : pricerole
                property var burgerbackground : backgroundrole

                Image {
                    anchors.horizontalCenter: nameText.horizontalCenter
                    width: root.width/10
                    height: root.height/4

                    source: burgerbackground

                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            burgerpath.currentIndex = index
                            main.currentpriceBurger = burgerprice
                        }
                    }
                }

                Text {
                    id: nameText
                    text: burgername
                    font.pointSize: 20
                    color: "black"
                    style: Text.Outline;
                    styleColor: "white"
                }

                Text {
                    id: priceText
                    text: burgerprice+" €"
                    font.pointSize: 15
                    color: "black"
                    style: Text.Outline;
                    styleColor: "white"
                }
            }
        }

        PathView {
            id: burgerpath
            anchors.centerIn: parent
            anchors.fill: parent
            model: m_shop
            delegate: delegate
            pathItemCount: 10

            path: Path {
                startX: root.width/9; startY: root.height-root.height/3
                PathQuad { x: root.width/2; y: root.height/10; controlX: root.width/9; controlY: root.height/10 }
                PathQuad { x: root.width-root.width/9; y: root.height-root.height/3; controlX: root.width-root.width/9; controlY: root.height/10 }
            }

            Component.onCompleted: {
                currentburger.text = m_shop.getNamerole(currentIndex)
                currentprice.text = m_shop.getPricerole(currentIndex)+" €"
                burgercover.source = m_shop.getBackgroundrole(currentIndex)
                burgercoverfullscreen.source = m_shop.getBackgroundrole(currentIndex)
                burgertextfullscreen.text = m_shop.getNamerole(currentIndex)
                main.currentpriceBurger = m_shop.getPricerole(currentIndex)
            }

            onCurrentIndexChanged: {
                currentburger.text = m_shop.getNamerole(currentIndex)
                currentprice.text = m_shop.getPricerole(currentIndex)+" €"
                burgercover.source = m_shop.getBackgroundrole(currentIndex)
                burgercoverfullscreen.source = m_shop.getBackgroundrole(currentIndex)
                burgertextfullscreen.text = m_shop.getNamerole(currentIndex)
                main.currentpriceBurger = m_shop.getPricerole(currentIndex)
            }
        }

        Rectangle{
            id: buybutton
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.right: parent.right
            anchors.rightMargin: 20
            width: 180
            height: 40
            color: "white"
            border.color: "black"
            border.width: 5
            radius: 15

            Text {
                id: textaddchart
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

                onPressed: {
                    buybutton.color = "black"
                    buybutton.border.color = "white"
                    textaddchart.color = "white"
                }
                onReleased: {
                    buybutton.color = "white"
                    buybutton.border.color = "black"
                    textaddchart.color = "black"
                }
            }
        }

        Image {
            id: burgercover
            height: root.height/6
            width: root.width/10
            anchors.top: parent.top
            anchors.topMargin: parent.height/4
            anchors.horizontalCenter: parent.horizontalCenter
            asynchronous: true
            smooth: true
            opacity: 1

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    burgercoverfullscreenspot.visible = true
                }
            }
        }

        Rectangle{
            id: burgercoverfullscreenspot
            visible: false
            anchors.centerIn: parent
            anchors.fill: parent

            Image {
                source: "./media/background.png"
                anchors.centerIn: parent
                anchors.fill: parent
                opacity: 0.4
            }

            Image {
                id: burgercoverfullscreen
                //height: parent.height-50
                //width: parent.width-50
                scale: 0.4
                anchors.centerIn: parent
                asynchronous: true
                smooth: true
                opacity: 1

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        burgercoverfullscreenspot.visible = false
                    }
                }
            }

            Text {
                id: burgertextfullscreen
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 25
                color: "black"
                style: Text.Outline;
                styleColor: "white"
            }


        }

    }

    Connections {
        target: m_kod
        function onPositionChanged(value) {
            burgerpath.currentIndex = value
        }
    }
}
