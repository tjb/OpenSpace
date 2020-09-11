#ifndef OSMODULES_H
#define OSMODULES_H

#include <QDialog>
#include <QWidget>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class osmodules;
}
QT_END_NAMESPACE

class osmodules : public QDialog
{
    Q_OBJECT

public slots:
    void listItemSelected();
    void listItemAdded();
    void listItemRemove();
    void listItemSave();
    void listItemCancelSave();
    void transitionToEditMode();
    void parseSelections();

public:
    explicit osmodules(std::vector<openspace::Profile::Module>& imported, QWidget *parent = nullptr);
    ~osmodules();

protected:
    //void resizeEvent(QResizeEvent* event);

private:
    QString createOneLineSummary(openspace::Profile::Module m);
    void transitionFromEditMode();
    void editBoxDisabled(bool disabled);

    Ui::osmodules *ui;
    QWidget* _parent;
    std::vector<openspace::Profile::Module>& _imported;
    std::vector<openspace::Profile::Module> _data;
    std::vector<QListWidgetItem*> _modulesListItems;
    bool _editModeNewItem = false;
};

#endif // OSMODULES_H