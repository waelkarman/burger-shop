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

        Component {
            id: delegate

            Item {
                id: wrapper
                height: imageitem.height+nameText.height
                width: imageitem.width
                opacity: PathView.isCurrentItem ? 1 : 0.7
                scale: PathView.isCurrentItem ? 0.3 : 0.2
                property var burgername : namerole
                property var burgerprice : pricerole
                property var burgerbackground : backgroundrole

                Image {
                    id: imageitem
                    anchors.centerIn: parent
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
                    anchors.top: imageitem.bottom
                    anchors.horizontalCenter: imageitem.horizontalCenter
                    text: burgername
                    font.pointSize:45
                    color: "black"
                    style: Text.Outline;
                    styleColor: "white"
                }

                Text {
                    id: priceText
                    anchors.top: nameText.bottom
                    anchors.horizontalCenter: imageitem.horizontalCenter
                    text: burgerprice+" €"
                    font.pointSize: 35
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

        Item{
            scale: 0.5
            anchors.top: parent.top
            anchors.topMargin: parent.height/4
            anchors.horizontalCenter: parent.horizontalCenter

            Image {
                id: burgercover
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

            Text {
                id: currentburger
                anchors.top: burgercover.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: "HelveticaS"
                font.pointSize: 55
                color: "black"
                style: Text.Outline;
                styleColor: "white"
            }

            Text {
                id: currentprice
                anchors.top: currentburger.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: "HelveticaS"
                font.pointSize: 40
                color: "black"
                style: Text.Outline;
                styleColor: "white"
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
                opacity: 0.6
            }

            Image {
                id: burgercoverfullscreen
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

    Image {
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        source: "./media/logo.jpeg"
        asynchronous: true
        smooth: true
        opacity: 1
    }

    Connections {
        target: m_kod
        function onPositionChanged(value) {
            burgerpath.currentIndex = value
        }
        function onButtonStatusChanged(value) {
            if (value===1 && burgercoverfullscreenspot.visible === false){
                burgercoverfullscreenspot.visible = true
            }else if(value===1 && burgercoverfullscreenspot.visible === true){
                burgercoverfullscreenspot.visible = false
            }
        }
    }
}
