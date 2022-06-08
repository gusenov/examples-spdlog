//
// Created by Abbas Gussenov on 08.06.2022.
//

#ifndef SIGNATURES_DEFINE_H
#define SIGNATURES_DEFINE_H

#define DEFINE_LOG_METHOD(params, args) \
void SpdLogger::Log(LogLevelType lvl, params) \
{ \
    m_pImpl->log(SpdLogLevel::Convert(lvl), args); \
} \
\
void SpdLogger::Trace   (params) { m_pImpl->trace   (args); } \
void SpdLogger::Debug   (params) { m_pImpl->debug   (args); } \
void SpdLogger::Info    (params) { m_pImpl->info    (args); } \
void SpdLogger::Warn    (params) { m_pImpl->warn    (args); } \
void SpdLogger::Error   (params) { m_pImpl->error   (args); } \
void SpdLogger::Critical(params) { m_pImpl->critical(args); }

#define DELETE_LOG_METHOD(params, args) \
void SpdLogger::Log(LogLevelType lvl, params) \
{ \
} \
\
void SpdLogger::Trace   (params) {  } \
void SpdLogger::Debug   (params) {  } \
void SpdLogger::Info    (params) {  } \
void SpdLogger::Warn    (params) {  } \
void SpdLogger::Error   (params) {  } \
void SpdLogger::Critical(params) {  }

#endif //SIGNATURES_DEFINE_H
