//
// Created by nsm on 2025-09-12.
//

#include "Include/WebpageBuilder.hpp"





WebpageBuilder::WebpageBuilder(const std::string &title, const std::string &languageCode)
{
    bodyClosed = false;
    documentText = new std::string;
    headClosed = false;
    htmlList = new std::list<std::string>();
    navClosed = false;
    this->title = title;
    titleIndexes = new std::list<int>;
    titleIterator = 0;
    wrapperClosed = false;


    htmlList->emplace_back("<!DOCTYPE html><html lang=\"");
    htmlList->emplace_back(languageCode);
    htmlList->emplace_back(R"("><head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"/><title>)");
    htmlList->emplace_back(title);
    titleIndexes->emplace_back(titleIterator);
    htmlList->emplace_back(R"(</title><link rel="stylesheet" type="text/css" href="/Resources/Styles/app.css"/>)");

    titleIterator++;
}





void WebpageBuilder::append(const std::string &text) const
{
    htmlList->emplace_back(text);
}






void WebpageBuilder::appendCSS(const std::string &uri) const
{
    if (bodyClosed || headClosed)
    {
        throw std::exception("Body and/or head closed; cannot append.");
    }


    htmlList->emplace_back(R"(<link rel="stylesheet" type="text/css" href=")");
    htmlList->emplace_back(uri);
    htmlList->emplace_back("\"/>");
}





void WebpageBuilder::appendJavaScript(const std::string &uri) const
{
    if (bodyClosed)
    {
        throw std::exception("Cannot append <script> to closed document.");
    }


    htmlList->emplace_back("<script src=\"");
    htmlList->emplace_back(uri);
    htmlList->emplace_back("\"></script>");
}






void WebpageBuilder::closeBody()
{
    if (headClosed != true && navClosed != true && wrapperClosed != true)
    {
        throw std::exception("Cannot close body.");
    }

    htmlList->emplace_back("</body></html>");

    bodyClosed = true;
}






void WebpageBuilder::closeHead()
{
    if (headClosed != false)
    {
        throw std::exception("Cannot close head.");
    }


    htmlList->emplace_back(R"(
</head>
<body>
<div id="wrapper">
    <header>
        <div id="notification-tray">
            <span id="clock"></span>
        </div>
        <h1>
)");
    htmlList->emplace_back(title);
    titleIndexes->emplace_back(titleIterator);
    htmlList->emplace_back("</h1><nav>");

    titleIterator++;
    headClosed = true;
}





void WebpageBuilder::closeNav()
{
    if (headClosed != true && navClosed && wrapperClosed != true && bodyClosed != true)
    {
        throw std::exception("Cannot close <nav>.");
    }

    htmlList->emplace_back("</nav></header>");

    navClosed = true;
}





void WebpageBuilder::closeWrapper() const
{
    if (headClosed != true && navClosed != true && wrapperClosed)
    {
        throw std::exception("Cannot close wrapper.");
    }

    htmlList->emplace_back(R"(</div><script src="/Scripts/app.js"></script>)");
}





size_t WebpageBuilder::getSize() const
{
    return documentText->size();
}








bool WebpageBuilder::isBodyClosed() const
{
    return bodyClosed;
}





bool WebpageBuilder::isHeadClosed() const
{
    return headClosed;
}





std::string WebpageBuilder::toString() const
{
    std::list<std::string>::iterator iterator;


    for (const std::string& i : *htmlList)
    {
        documentText->append(i);
    }

    return *documentText;
}
