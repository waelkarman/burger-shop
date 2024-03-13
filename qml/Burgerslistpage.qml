import QtQuick
import QtQuick.Controls
import QtQml

Item {
    id:main
    width: 800
    height: 600
    property int currentpriceBurger : 0

    Rectangle {
        id: root
        anchors.fill: parent
        color: "black"   

        Image {
            id: background0
            anchors.fill: parent
            source: "./media/background0.jpg"
            opacity: 0.3
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
            anchors.top: parent.top
            anchors.topMargin: 50
            anchors.left: parent.left
            anchors.leftMargin: 50
            text: "Burger Shop"
            style: Text.Outline;
            styleColor: "black"
            font.family: "HelveticaS"
            font.pointSize: 24
            color: "white"
        }

        Component {
            id: delegate

            Column {
                id: wrapper
                opacity: PathView.isCurrentItem ? 1 : 0.6
                property var burgername : namerole
                property var burgerprice : pricerole
                property var burgerbackground : backgroundrole

                Image {
                    anchors.horizontalCenter: nameText.horizontalCenter
                    width: 55; height: 55
                    source: "./media/burger.png"

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
                    font.pointSize: 8
                    color: "white"
                    style: Text.Outline;
                    styleColor: "black"
                }

                Text {
                    id: priceText
                    text: burgerprice+" €"
                    font.pointSize: 7
                    color: "white"
                    style: Text.Outline;
                    styleColor: "black"
                }
            }
        }

        PathView {
            id: burgerpath
            anchors.centerIn: parent
            anchors.fill: parent
            model: m_shop
            delegate: delegate
            path: Path {
                startX: root.width/9; startY: root.height-root.height/3
                PathQuad { x: root.width+root.width/10; y: root.height/10; controlX: root.width/5; controlY: root.height/6 }
            }

            Component.onCompleted: {
                currentburger.text = itemAtIndex(currentIndex).burgername
                currentprice.text = itemAtIndex(currentIndex).burgerprice+" €"
                burgercover.source = itemAtIndex(currentIndex).burgerbackground
                burgercoverfullscreen.source = itemAtIndex(currentIndex).burgerbackground
                main.currentpriceBurger = itemAtIndex(currentIndex).burgerprice
            }

            onCurrentIndexChanged: {
                currentburger.text = itemAtIndex(currentIndex).burgername
                currentprice.text = itemAtIndex(currentIndex).burgerprice+" €"
                burgercover.source = itemAtIndex(currentIndex).burgerbackground
                burgercoverfullscreen.source = itemAtIndex(currentIndex).burgerbackground
                main.currentpriceBurger = itemAtIndex(currentIndex).burgerprice
            }
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
                    burgercoverfullscreen.visible = true
                }
            }
        }

        Image {
            id: burgercoverfullscreen
            height: parent.height-50
            width: parent.width-50
            visible: false
            anchors.centerIn: parent
            asynchronous: true
            smooth: true
            opacity: 1

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    burgercoverfullscreen.visible = false
                }
            }
        }
    }
}
