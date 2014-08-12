#include "datum/string_datum.h"

StringDatum::StringDatum(QString name, QObject* parent)
    : EvalDatum(name, parent)
{
    // Nothing to do here
}

StringDatum::StringDatum(QString name, QString expr, QObject* parent)
    : StringDatum(name, parent)
{
    setExpr(expr);
}

QString StringDatum::prepareExpr(QString s) const
{
    return wrap ?  ("'" + s + "'") : s;
}

PyObject* StringDatum::getCurrentValue()
{
    PyObject* v;

    wrap = false;
    v = EvalDatum::getCurrentValue();
    if (v)
    {
        return v;
    }

    wrap = true;
    v = EvalDatum::getCurrentValue();
    return v;
}
