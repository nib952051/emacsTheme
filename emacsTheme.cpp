#include <QKeySequence>

#include <qpa/qplatformtheme.h>
#include <qpa/qplatformthemeplugin.h>
#include <private/qgenericunixthemes_p.h>

#ifdef QT_NO_SHORTCUT
#error Nothing to do here
#endif

class EmacsPlatformTheme : public QGenericUnixTheme
{
public:
    QList<QKeySequence> keyBindings(QKeySequence::StandardKey key) const override;
};

class EmacsPlatformThemePlugin : public QPlatformThemePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QPlatformThemeFactoryInterface_iid FILE "emacs.json")
public:
    explicit EmacsPlatformThemePlugin(QObject *parent = nullptr) : QPlatformThemePlugin(parent) {}

    QPlatformTheme *create(const QString &key, const QStringList &paramList) override;
};

QPlatformTheme *EmacsPlatformThemePlugin::create(const QString &key, const QStringList &)
{
    if (key.compare(QLatin1String("emacs"), Qt::CaseInsensitive) == 0)
        return new EmacsPlatformTheme;
    return nullptr;
}

QList<QKeySequence> EmacsPlatformTheme::keyBindings(QKeySequence::StandardKey key) const
{
    switch (key) {
    case QKeySequence::Open:
        return {QKeySequence(Qt::CTRL + Qt::Key_X, Qt::CTRL + Qt::Key_F)};
    case QKeySequence::Close:
        return {QKeySequence(Qt::CTRL + Qt::Key_X, Qt::CTRL + Qt::Key_K)};
    case QKeySequence::Save:
        return {QKeySequence(Qt::CTRL + Qt::Key_X, Qt::CTRL + Qt::Key_S)};
    case QKeySequence::Delete:
        return {QKeySequence(Qt::CTRL + Qt::Key_X, Qt::CTRL + Qt::Key_D)};
    case QKeySequence::Cut:
        return {QKeySequence(Qt::CTRL + Qt::Key_X, Qt::CTRL + Qt::Key_W)};
    case QKeySequence::Copy:
        return {QKeySequence(Qt::ALT + Qt::Key_W)};
    case QKeySequence::Paste:
        return {QKeySequence(Qt::CTRL + Qt::Key_Y)};
    case QKeySequence::Undo:
        return {QKeySequence(Qt::CTRL + Qt::Key_Underscore), QKeySequence(Qt::CTRL + Qt::Key_X, Qt::Key_U)};
    case QKeySequence::Back:
        return {QKeySequence(Qt::CTRL + Qt::Key_X, Qt::CTRL + Qt::Key_Left)};
    case QKeySequence::Forward:
        return {QKeySequence(Qt::CTRL + Qt::Key_X, Qt::CTRL + Qt::Key_Right)};
    case QKeySequence::Find:
    case QKeySequence::FindNext:
        return {QKeySequence(Qt::CTRL + Qt::Key_S)};
    case QKeySequence::FindPrevious:
        return {QKeySequence(Qt::CTRL + Qt::Key_R)};
    case QKeySequence::MoveToNextChar:
        return {QKeySequence(Qt::CTRL + Qt::Key_F)};
    case QKeySequence::MoveToPreviousChar:
        return {QKeySequence(Qt::CTRL + Qt::Key_B)};
    case QKeySequence::MoveToNextWord:
        return {QKeySequence(Qt::ALT + Qt::Key_F)};
    case QKeySequence::MoveToPreviousWord:
        return {QKeySequence(Qt::ALT + Qt::Key_B)};
    case QKeySequence::MoveToNextLine:
        return {QKeySequence(Qt::CTRL + Qt::Key_N)};
    case QKeySequence::MoveToPreviousLine:
        return {QKeySequence(Qt::CTRL + Qt::Key_P)};
    case QKeySequence::MoveToNextPage:
        return {QKeySequence(Qt::Key_PageDown)};
    case QKeySequence::MoveToPreviousPage:
        return {QKeySequence(Qt::Key_PageUp)};
    case QKeySequence::MoveToStartOfLine:
        return {QKeySequence(Qt::CTRL + Qt::Key_A)};
    case QKeySequence::MoveToEndOfLine:
        return {QKeySequence(Qt::CTRL + Qt::Key_E)};
//        MoveToStartOfBlock and so on
    default:
        break;
    }
    return {};
}

#include "emacsTheme.moc"
