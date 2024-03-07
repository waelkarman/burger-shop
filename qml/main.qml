import QtQuick
import QtQuick.Controls

Item{
    width: 800
    height: 600

    SwipeView {
        id: view

        currentIndex: 0
        anchors.fill: parent

        Bookslistpage{
            id: firstPage
        }

        Shoppingcartpage {
            id: secondPage
        }

    }
}

