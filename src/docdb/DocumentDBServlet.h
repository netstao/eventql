/**
 * Copyright (c) 2015 - The CM Authors <legal@clickmatcher.com>
 *   All Rights Reserved.
 *
 * This file is CONFIDENTIAL -- Distribution or duplication of this material or
 * the information contained herein is strictly forbidden unless prior written
 * permission is obtained.
 */
#pragma once
#include "stx/http/httpservice.h"
#include "stx/json/json.h"
#include "stx/random.h"
#include "common/AnalyticsAuth.h"
#include "common/ConfigDirectory.h"
#include "docdb/DocumentDB.h"

using namespace stx;

namespace cm {

class DocumentDBServlet {
public:

  DocumentDBServlet(DocumentDB* docdb);

  void handle(
      const AnalyticsSession& session,
      const stx::http::HTTPRequest* req,
      stx::http::HTTPResponse* res);

protected:

  void documentREST(
      const URI& uri,
      const AnalyticsSession& session,
      const http::HTTPRequest* req,
      http::HTTPResponse* res);

  void fetchDocument(
      const String& type,
      const SHA1Hash& uuid,
      const URI& uri,
      const AnalyticsSession& session,
      const http::HTTPRequest* req,
      http::HTTPResponse* res);

  void createDocument(
      const String& type,
      const URI& uri,
      const AnalyticsSession& session,
      const http::HTTPRequest* req,
      http::HTTPResponse* res);

  void updateDocument(
      const String& type,
      const SHA1Hash& uuid,
      const URI& uri,
      const AnalyticsSession& session,
      const http::HTTPRequest* req,
      http::HTTPResponse* res);

  void listDocuments(
      const AnalyticsSession& session,
      const http::HTTPRequest* req,
      http::HTTPResponse* res);

  void fetchSQLQuery(
      const SHA1Hash& uuid,
      const AnalyticsSession& session,
      const http::HTTPRequest* req,
      http::HTTPResponse* res);

  void createSQLQuery(
      const AnalyticsSession& session,
      const http::HTTPRequest* req,
      http::HTTPResponse* res);

  void updateSQLQuery(
      const SHA1Hash& uuid,
      const AnalyticsSession& session,
      const http::HTTPRequest* req,
      http::HTTPResponse* res);

  void renderSQLQuery(const Document& doc, Buffer* buf);

  DocumentDB* docdb_;
};

}