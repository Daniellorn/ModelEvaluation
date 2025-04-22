import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "UI/TopBar"
import "UI/Separator"
import "UI/LeftScreen"
import "UI/RightScreen"

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Model")

    property string selectedModel: "Klasyfikacyjny"

    TopBar {
        id: topBar

        onComboBox1CurrentTextChanged: (newValue) => {
            selectedModel = newValue
            console.log("Wybrano model:", selectedModel)
        }
    }

    Separator {
        id: separator
    }

    LeftScreen {
        id: leftScreen
        model: selectedModel
    }

    RightScreen {
        id: rightScreen
        model: selectedModel
    }

}
