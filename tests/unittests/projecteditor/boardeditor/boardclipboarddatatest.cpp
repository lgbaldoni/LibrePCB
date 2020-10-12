/*
 * LibrePCB - Professional EDA for everyone!
 * Copyright (C) 2013 LibrePCB Developers, see AUTHORS.md for contributors.
 * https://librepcb.org/
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

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include <librepcb/projecteditor/boardeditor/boardclipboarddata.h>

#include <QtCore>

/*******************************************************************************
 *  Namespace
 ******************************************************************************/
namespace librepcb {
namespace project {
namespace editor {
namespace tests {

/*******************************************************************************
 *  Test Class
 ******************************************************************************/

class BoardClipboardDataTest : public ::testing::Test {};

/*******************************************************************************
 *  Test Methods
 ******************************************************************************/

TEST(BoardClipboardDataTest, testToFromMimeDataEmpty) {
  // Create data
  Uuid uuid = Uuid::createRandom();
  Point pos(Length(12345), Length(54321));

  // Create object
  BoardClipboardData data(uuid, pos);

  // Serialize to MIME data
  std::unique_ptr<QMimeData> mime = data.toMimeData();

  // Load from MIME data and validate
  std::unique_ptr<BoardClipboardData> newData =
      BoardClipboardData::fromMimeData(mime.get());
  EXPECT_EQ(uuid, newData->getBoardUuid());
  EXPECT_EQ(pos, newData->getCursorPos());
  EXPECT_EQ(data.getDevices(), newData->getDevices());
  EXPECT_EQ(data.getNetSegments(), newData->getNetSegments());
  EXPECT_EQ(data.getPlanes(), newData->getPlanes());
  EXPECT_EQ(data.getPolygons(), newData->getPolygons());
  EXPECT_EQ(data.getStrokeTexts(), newData->getStrokeTexts());
  EXPECT_EQ(data.getHoles(), newData->getHoles());
  EXPECT_EQ(data.getPadPositions(), newData->getPadPositions());
}

TEST(BoardClipboardDataTest, testToFromMimeDataPopulated) {
  // Create data
  Uuid uuid = Uuid::createRandom();
  Point pos(Length(12345), Length(54321));
  StrokeTextList strokeTexts;
  strokeTexts.append(std::make_shared<StrokeText>(
      Uuid::createRandom(), GraphicsLayerName("foo"), "text 1", Point(1, 2),
      Angle(3), PositiveLength(4), UnsignedLength(5), StrokeTextSpacing(),
      StrokeTextSpacing(Ratio(6)), Alignment(HAlign::left(), VAlign::top()),
      false, true));
  strokeTexts.append(std::make_shared<StrokeText>(
      Uuid::createRandom(), GraphicsLayerName("bar"), "text 2", Point(10, 20),
      Angle(30), PositiveLength(40), UnsignedLength(0),
      StrokeTextSpacing(Ratio(6)), StrokeTextSpacing(),
      Alignment(HAlign::center(), VAlign::bottom()), true, false));

  // Create object
  BoardClipboardData data(uuid, pos);
  data.getDevices().append(std::make_shared<BoardClipboardData::Device>(
      Uuid::createRandom(), Uuid::createRandom(), Uuid::createRandom(),
      Point::fromMm(1, 2), Angle::fromDeg(45), false, strokeTexts));
  data.getDevices().append(std::make_shared<BoardClipboardData::Device>(
      Uuid::createRandom(), Uuid::createRandom(), Uuid::createRandom(),
      Point::fromMm(10, 20), Angle::fromDeg(-45), true, strokeTexts));

  // Serialize to MIME data
  std::unique_ptr<QMimeData> mime = data.toMimeData();

  // Load from MIME data and validate
  std::unique_ptr<BoardClipboardData> newData =
      BoardClipboardData::fromMimeData(mime.get());
  EXPECT_EQ(uuid, newData->getBoardUuid());
  EXPECT_EQ(pos, newData->getCursorPos());
  EXPECT_EQ(data.getDevices(), newData->getDevices());
  EXPECT_EQ(data.getNetSegments(), newData->getNetSegments());
  EXPECT_EQ(data.getPlanes(), newData->getPlanes());
  EXPECT_EQ(data.getPolygons(), newData->getPolygons());
  EXPECT_EQ(data.getStrokeTexts(), newData->getStrokeTexts());
  EXPECT_EQ(data.getHoles(), newData->getHoles());
  EXPECT_EQ(data.getPadPositions(), newData->getPadPositions());
}

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace tests
}  // namespace editor
}  // namespace project
}  // namespace librepcb
