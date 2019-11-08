#ifndef APPROVALTESTS_CPP_QT_CATCH2QTSTRINGMAKER_H
#define APPROVALTESTS_CPP_QT_CATCH2QTSTRINGMAKER_H

#ifdef CATCH_VERSION_MAJOR
#include <QColor>
#include <QStringBuilder>
namespace Catch
{
    template <> struct StringMaker<QColor>
    {
        static std::string convert(QColor const& color)
        {
            // clang-format off
            const QString result = "(" %
                                   QString::number(color.redF()) % ", " %
                                   QString::number(color.greenF()) % ", " %
                                   QString::number(color.blueF()) %
                                   "), alpha = " %
                                   QString::number(color.alphaF(), 'g', 20);
            // clang-format on
            return result.toStdString();
        }
    };

    template <> struct StringMaker<QString>
    {
        static std::string convert(QString const& string)
        {
            return string.toStdString();
        }
    };
} // namespace Catch
#endif // CATCH_VERSION_MAJOR

#endif //APPROVALTESTS_CPP_QT_CATCH2QTSTRINGMAKER_H
