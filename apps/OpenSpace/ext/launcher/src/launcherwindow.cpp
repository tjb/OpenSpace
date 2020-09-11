#include <openspace/scene/profile.h>
#include "launcherwindow.h"
#include "profileedit.h"
#include "./ui_launcherwindow.h"
#include <QPixmap>
#include "filesystemaccess.h"
#include <sstream>


LauncherWindow::LauncherWindow(std::string basePath, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LauncherWindow)
    , _fileAccess_profiles(".profile", {"./"}, true, false)
    , _fileAccess_winConfigs(".xml", {"./"}, true, false)
    , _filesystemAccess(".asset", {"scene", "global", "customization", "examples"},
                        true, true)
    , _basePath(QString::fromUtf8(basePath.c_str()))
    , _pData({_metaData,
             _moduleData,
             _assetData,
             _reportAssetsInFilesystem,
             _propsData,
             _keybindingsData,
             _deltaTimesData,
             _timeData,
             _cameraData,
             _markNodesData,
             _addedScriptsData})
{
    ui->setupUi(this);
    QString logoPath = _basePath + "/data/openspace-horiz-logo.png";
    QPixmap pix(logoPath);
    ui->logolabel->setPixmap(pix.scaled(400, 120, Qt::KeepAspectRatio));
    connect(ui->newButton, SIGNAL(released()), this, SLOT(openWindow_new()));
    connect(ui->editButton, SIGNAL(released()), this, SLOT(openWindow_edit()));
    connect(ui->buttonSim, SIGNAL(released()), this, SLOT(simulateData()));
    populateProfilesList();
    populateWindowConfigsList();
}

void LauncherWindow::populateProfilesList() {
    std::string reportProfiles = _fileAccess_profiles.useQtFileSystemModelToTraverseDir(
        _basePath + "/data/profiles");
    std::stringstream instream(reportProfiles);
    std::string iline;
    QStringList profilesListLine;
    while (std::getline(instream, iline)) {
        profilesListLine << iline.c_str();
    }
    ui->comboBoxProfiles->addItems(profilesListLine);
}

void LauncherWindow::populateWindowConfigsList() {
    std::string reportConfigs = _fileAccess_winConfigs.useQtFileSystemModelToTraverseDir(
        _basePath + "/config");
    std::stringstream instream(reportConfigs);
    std::string iline;
    QStringList windowConfigsListLine;
    while (std::getline(instream, iline)) {
        windowConfigsListLine << iline.c_str();
    }
    ui->comboBoxWindowConfigs->addItems(windowConfigsListLine);
}

void LauncherWindow::openWindow_new() {
    clearData();
    myEditorWindow = new ProfileEdit(_pData);
    myEditorWindow->exec();
}

void LauncherWindow::openWindow_edit() {
    //std::string editProfilePath = _basePath.toUtf8().constData();
    //editProfilePath += "/data/profiles/";
    //editProfilePath += ui->comboBoxProfiles->currentText().toUtf8().constData();
    //editProfilePath += ".profile";
    //myEditorWindow = new editorwindow(_basePath + "/data/assets", editProfilePath);
    myEditorWindow = new ProfileEdit(_pData);

    int selectedProfileIdx = ui->comboBoxProfiles->currentIndex();
    QString profileToSet = ui->comboBoxProfiles->itemText(selectedProfileIdx);
    myEditorWindow->setProfileName(profileToSet);

    myEditorWindow->exec();
}

void LauncherWindow::receiveAssets(std::vector<std::string> results) {
    std::string windowText;
    for (std::string line : results) {
        windowText += line + "\n";
    }
}

LauncherWindow::~LauncherWindow() {
    delete ui;
    delete myEditorWindow;
}

void LauncherWindow::simulateData() {
    initialize_meta();
    initialize_modules();
    initialize_assets();
    initialize_properties();
    initialize_keybindings();
    initialize_deltaTimes();
    initialize_time();
    initialize_camera();
    initialize_markNodes();
    initialize_addedScripts();
}

void LauncherWindow::clearData() {
    _metaData = {"", "", "", "", "", ""};
    _moduleData.clear();
    _assetData.clear();
    _propsData.clear();
    _keybindingsData.clear();
    _deltaTimesData._times.clear();
    _timeData.time = "";
    _cameraData.type = Camera::Type::Nav;
    _cameraData.nav = {"", "", "", {"", "", ""}, {"", "", ""}, "", ""};
    _cameraData.geo = {"", "", "", ""};
    _markNodesData.clear();
    _addedScriptsData = "";
}

void LauncherWindow::initialize_meta() {
    _metaData.name = "The meta name";
    _metaData.version = "0.15.2";
    _metaData.description = "Description here";
    _metaData.author = "Author";
    _metaData.url = "http://openspaceproject.com";
    _metaData.license = "MIT";
}

void LauncherWindow::initialize_modules() {
    _moduleData = {
        {
            "base",
            "Do stuff for base if it's loaded",
            ""
        },
        {
            "globebrowsing",
            "",
            ""
        },
        {
            "gaia",
            "",
            "Command if gaia not loaded"
        },
        {
            "kameleon",
            "script {\n  line1\n  line2\n}",
            "Command if gaia not loaded"
        },
    };

}

void LauncherWindow::initialize_assets() {
    _reportAssetsInFilesystem = _filesystemAccess.useQtFileSystemModelToTraverseDir(
        "/home/gene/Desktop/OpenSpace/data/assets");

    _assetData = {
        {"", "base"},
        {"examples", "spheres"},
        {"examples", "slidedeck"},
        {"scene/milkyway/gaia", "galah"},
        {"scene/solarsystem/missions/pioneer", "pioneer10"},
        {"scene/solarsystem/missions/spacex", "roadster"},
        {"scene/solarsystem/sun", "glare"},
        {"scene/solarsystem/sun", "marker"},
        {"util", "layer_helper"},
        {"customization", "gui"}
    };
}

void LauncherWindow::initialize_properties() {
    _propsData = {
        {
            openspace::Profile::Property::SetType::SetPropertyValueSingle,
            "NavigationHandler.OrbitalNavigator.FollowAnchorNodeRotationDistance",
            "20.0"
        },
        {
            openspace::Profile::Property::SetType::SetPropertyValue,
            "Scene.Pluto.Renderable.Enabled",
            "false"
        },
        {
            openspace::Profile::Property::SetType::SetPropertyValueSingle,
            "Scene.Charon.Renderable.Enabled",
            "false"
        },
        {
            openspace::Profile::Property::SetType::SetPropertyValueSingle,
            "Scene.PlutoBarycenterTrail.Renderable.Enabled",
            "false"
        },
        {
            openspace::Profile::Property::SetType::SetPropertyValueSingle,
            "NavigationHandler.OrbitalNavigator.FollowAnchorNodeRotationDistance",
            "20.0"
        },
        {
            openspace::Profile::Property::SetType::SetPropertyValue,
            "Scene.Pluto.Renderable.Enabled",
            "false"
        },
        {
            openspace::Profile::Property::SetType::SetPropertyValueSingle,
            "Scene.Styx.Renderable.Enabled",
            "false"
        },
        {
            openspace::Profile::Property::SetType::SetPropertyValueSingle,
            "Scene.PlutoBarycenterTrail.Renderable.Enabled",
            "false"
        },
        {
            openspace::Profile::Property::SetType::SetPropertyValueSingle,
            "NavigationHandler.OrbitalNavigator.FollowAnchorNodeRotationDistance",
            "20.0"
        },
        {
            openspace::Profile::Property::SetType::SetPropertyValue,
            "Scene.Pluto.Renderable.Enabled",
            "false"
        },
        {
            openspace::Profile::Property::SetType::SetPropertyValueSingle,
            "Scene.StyxRenderableTrail.Renderable.Enabled",
            "false"
        },
        {
            openspace::Profile::Property::SetType::SetPropertyValueSingle,
            "Scene.PlutoBarycenterTrail.Renderable.Enabled",
            "false"
        },
    };
}

void LauncherWindow::initialize_keybindings() {
    _keybindingsData = {
        {
            {openspace::Key::Equal, openspace::KeyModifier::Control},
            "Documentation for ctrl+=",
            "Name for the keybinding",
            "/Path/to/keys",
            true,
            "openspace.keybindings.local.variable.1"
        },
        {
            {openspace::Key::KeypadAdd, openspace::KeyModifier::Shift},
            "Documentation for shift++",
            "Name for the keybinding",
            "/Path/to/keys",
            true,
            "openspace.keybindings.local.variable.2"
        },
        {
            {openspace::Key::Keypad3, openspace::KeyModifier::NoModifier},
            "Documentation for '3'",
            "Name for the keybinding",
            "/Path/to/keys",
            false,
            "openspace.keybindings.local.variable.3"
        },
    };
}

void LauncherWindow::initialize_deltaTimes() {
    std::vector<int> dt = {1, 2, 5, 10, 30,
    60, 120, 300, 600, 1800,
    3600, 7200, 10800, 21600, 43200,
     86400, 172800, 345600, 604800};
    _deltaTimesData.loadValues(dt);
}

void LauncherWindow::initialize_time() {
    _timeData.type = openspace::Profile::Time::Type::Absolute;
    _timeData.time = "2011-04-17T21:23:59";
}

void LauncherWindow::initialize_camera() {
    _cameraData.type = Camera::Type::Nav;
    _cameraData.nav = {"Earth", "Moon", "SUNREF", {"1", "2", "3"}, {"4", "5", "6"}, "180.0", "359.9"};
}

void LauncherWindow::initialize_markNodes() {
    _markNodesData = {"Earth", "Moon", "Mars", "Jupiter", "Sun"};
}

void LauncherWindow::initialize_addedScripts() {
    _addedScriptsData = "line1\nline2\nline3\nline4\nline5";
}