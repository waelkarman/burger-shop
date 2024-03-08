import QtQuick
import QtQuick.Controls

Item {
    width: 800
    height: 600

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
                            console.log("price of : ",burgerprice)
                        }
                    }
                }

                Text {
                    id: nameText
                    text: burgername
                    font.pointSize: 8
                    color: "white"
                }

                Text {
                    id: priceText
                    text: burgerprice+" €"
                    font.pointSize: 7
                    color: "white"
                }
            }
        }

        PathView {
            property var model_name: m_shop

            id: burgerpath
            anchors.centerIn: parent
            anchors.fill: parent
            model: model_name
            delegate: delegate
            path: Path {
                startX: root.width/9; startY: root.height-root.height/3
                PathQuad { x: root.width+root.width/10; y: root.height/10; controlX: root.width/5; controlY: root.height/6 }
            }

            onCurrentIndexChanged: {
                currentburger.text = itemAtIndex(currentIndex).burgername
                currentprice.text = itemAtIndex(currentIndex).burgerprice+" €"
                burgercover.source = itemAtIndex(currentIndex).burgerbackground
            }
        }

        Text {
            id: currentburger
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 50
            anchors.right: parent.right
            anchors.rightMargin: 50
            text: itemAtIndex(currentIndex).burgername
            font.family: "HelveticaS"
            font.pointSize: 24
            color: "white"
        }

        Text {
            id: currentprice
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.right: parent.right
            anchors.rightMargin: 50
            text: itemAtIndex(currentIndex).burgerprice+" €"
            font.family: "HelveticaS"
            font.pointSize: 16
            color: "white"
        }
    }
}
