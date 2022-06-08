//
// Created by Abbas Gussenov on 08.06.2022.
//

#ifndef SIGNATURES_OVERRIDE_H
#define SIGNATURES_OVERRIDE_H

#define DECLARE_LOG_METHOD(params) \
    void Log(LogLevelType, params) override; \
\
    void Trace   (params) override; \
    void Debug   (params) override; \
    void Info    (params) override; \
    void Warn    (params) override; \
    void Error   (params) override; \
    void Critical(params) override;

#endif //SIGNATURES_OVERRIDE_H
