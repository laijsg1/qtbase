/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QBACKINGSTORE_KMS_H
#define QBACKINGSTORE_KMS_H

#include <qpa/qplatformbackingstore.h>
#include <QImage>

QT_BEGIN_NAMESPACE

class QOpenGLContext;
class QOpenGLShaderProgram;

class QKmsBackingStore : public QPlatformBackingStore
{
public:
    QKmsBackingStore(QWindow *window);
    ~QKmsBackingStore();

    QPaintDevice *paintDevice();

    void beginPaint(const QRegion &);
    void endPaint();

    void flush(QWindow *window, const QRegion &region, const QPoint &offset);
    void resize(const QSize &size, const QRegion &staticContents);

private:
    QOpenGLContext *m_context;
    QImage m_image;
    uint m_texture;
    QOpenGLShaderProgram *m_program;
};

QT_END_NAMESPACE

#endif
