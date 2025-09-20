//
// Created by nsm on 2025-09-12.
//

#ifndef SERVER_WEBPAGEBUILDER_H
#define SERVER_WEBPAGEBUILDER_H

#include <list>
#include <string>


class WebpageBuilder
{
public:
    /**
     * Constructs a webpage builder, used to produce pages for the site.
     * @param title Title of the document.
     * @param languageCode An ISO-639-2 langauge code.
     */
    WebpageBuilder(const std::string &title, const std::string &languageCode);

    /**
     * Append arbitrary text to the document.
     * @param text Arbitrary text.
     */
    void append(const std::string &text) const;

    /**
     * Add external CSS.
     * @param uri URI of the CSS file.
     */
    void appendCSS(const std::string &uri) const;

    /**
     * Add external JavaScript.
     * @param uri URI of the JavaScript file.
     */
    void appendJavaScript(const std::string &uri) const;

    /**
     * Append the tags that close the document. Once called, the document can no longer be modified.
     */
    void closeBody();

    /**
     * Append tags that close the document's head (metadata) section. Must be called before closeNav.
     */
    void closeHead();

    /**
     * Close the navigation section of the document. This must be done after <head> is closed and before the wrapper is closed.
     */
    void closeNav();

    /**
     * Close the wrapper portion of the document. This is required to insert scripts in the body.
     */
    void closeWrapper() const;

    size_t getSize() const;

    [[nodiscard]] bool isBodyClosed() const;

    [[nodiscard]] bool isHeadClosed() const;

    /**
     * Get the webpage's raw HTML.
     * @return Textual contents of the document.
     */
    [[nodiscard]] auto toString() const -> std::string;





private:
    bool bodyClosed;
    std::string *documentText;
    bool headClosed;
    std::list<std::string> *htmlList;
    bool navClosed;
    std::string title;
    std::list<int> *titleIndexes;
    unsigned int titleIterator;
    bool wrapperClosed;
};


#endif //SERVER_WEBPAGEBUILDER_H