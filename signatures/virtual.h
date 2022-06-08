//
// Created by Abbas Gussenov on 08.06.2022.
//

#ifndef SIGNATURES_VIRTUAL_H
#define SIGNATURES_VIRTUAL_H

#define DECLARE_LOG_METHOD(params) \
    virtual void Log(LogLevelType, params) = 0; \
\
    virtual void Trace   (params) = 0; \
    virtual void Debug   (params) = 0; \
    virtual void Info    (params) = 0; \
    virtual void Warn    (params) = 0; \
    virtual void Error   (params) = 0; \
    virtual void Critical(params) = 0;

#endif //SIGNATURES_VIRTUAL_H
