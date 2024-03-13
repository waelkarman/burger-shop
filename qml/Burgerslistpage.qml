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
                main.currentpriceBurger = itemAtIndex(currentIndex).burgerprice
            }

            onCurrentIndexChanged: {
                currentburger.text = itemAtIndex(currentIndex).burgername
                currentprice.text = itemAtIndex(currentIndex).burgerprice+" €"
                burgercover.source = itemAtIndex(currentIndex).burgerbackground
                main.currentpriceBurger = itemAtIndex(currentIndex).burgerprice
            }
        }
    }
}
