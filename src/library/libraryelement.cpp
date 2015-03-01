/*
 * EDA4U - Professional EDA for everyone!
 * Copyright (C) 2013 Urban Bruhin
 * http://eda4u.ubruhin.ch/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*****************************************************************************************
 *  Includes
 ****************************************************************************************/

#include <QtCore>
#include "libraryelement.h"
#include "../common/file_io/xmldomelement.h"

namespace library {

/*****************************************************************************************
 *  Constructors / Destructor
 ****************************************************************************************/

LibraryElement::LibraryElement(const FilePath& xmlFilePath,
                               const QString& xmlRootNodeName) throw (Exception) :
    LibraryBaseElement(xmlFilePath, xmlRootNodeName)
{
}

LibraryElement::~LibraryElement() noexcept
{
}

/*****************************************************************************************
 *  Protected Methods
 ****************************************************************************************/

void LibraryElement::parseDomTree(const XmlDomElement& root) throw (Exception)
{
    LibraryBaseElement::parseDomTree(root);

    // read category UUIDs
    for (XmlDomElement* node = root.getFirstChild("categories/category", true, false);
         node; node = node->getNextSibling("category"))
    {
        mCategories.append(node->getText<QUuid>());
    }
}

/*****************************************************************************************
 *  End of File
 ****************************************************************************************/

} // namespace library
