import QtQuick
import QtQuick.Controls

Rectangle {
    id: root
    width: 800
    height: 600
    // color: "black"

    Component {
        id: delegate
        Column {
            id: wrapper

            opacity: PathView.isCurrentItem ? 1 : 0.5

            Image {
                anchors.horizontalCenter: nameText.horizontalCenter
                width: 64; height: 64
                source: "./book.png"
            }
            Text {
                id: nameText
                text: model.display
                font.pointSize: 16
            }
        }
    }

    PathView {
        anchors.centerIn: parent
        anchors.fill: parent
        model: m_shop
        delegate: delegate
        path: Path {
            startX: root.width/2; startY: root.height/2
            PathQuad { x: root.width/4; y: root.height/3; controlX: root.width/4; controlY: root.height/2 }
            PathQuad { x: root.width/2; y: root.height/5; controlX: root.width/4; controlY: root.height/5 }
            PathQuad { x: root.width/2+root.width/4; y: root.height/3; controlX: root.width/2+root.width/4; controlY: root.height/5 }
            PathQuad { x: root.width/2; y: root.height/2; controlX: root.width/2+root.width/4; controlY: root.height/2 }
        }
    }
}
