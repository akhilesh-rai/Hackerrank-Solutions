#include"../libs/Algorithms/Implementation/SurfaceArea/SurfaceArea.h"
#include"../libs/Algorithms/Implementation/SurfaceArea/SurfaceArea.cpp"
#include "gtest/gtest.h"

class ToyTest : public ::testing::Test
{
protected:
    // Test parameters
    int toyHeight;
    int toyWidth;
    loc cell1Loc;
    loc cell2Loc;
    loc cell3Loc;
    cell* cell1;
    cell* cell2;
    cell* cell3;

    void SetUp() override
    {
        // Initialize test parameters
        toyHeight = 3;
        toyWidth = 3;
        cell1Loc = { 0, 0, 0 };
        cell2Loc = { 0, 1, 0 };
        cell3Loc = { 1, 0, 0 };
        cell1 = new cell(cell1Loc);
        cell2 = new cell(cell2Loc);
        cell3 = new cell(cell3Loc);
    }

    void TearDown() override
    {
        // Free memory
        delete cell1;
        delete cell2;
        delete cell3;
    }
};

TEST_F(ToyTest, getCell_returnsCorrectCell)
{
    // Arrange
    Toy toy(toyHeight, toyWidth);
    toy.addCell(cell1);

    // Act
    cell* result = toy.getCell(cell1Loc);

    // Assert
    EXPECT_EQ(cell1, result);
}

TEST_F(ToyTest, getCell_returnsNullptrForInvalidLocation)
{
    // Arrange
    Toy toy(toyHeight, toyWidth);
    toy.addCell(cell1);

    // Act
    cell* result = toy.getCell(cell2Loc);

    // Assert
    EXPECT_EQ(nullptr, result);
}

TEST_F(ToyTest, getCellInDir_returnsCorrectCell)
{
    // Arrange
    Toy toy(toyHeight, toyWidth);
    toy.addCell(cell1);
    toy.addCell(cell2);

    // Act
    cell* result = toy.getCellInDir(cell1Loc, dir::EAST);

    // Assert
    EXPECT_EQ(cell2, result);
}

TEST_F(ToyTest, getCellInDir_returnsNullptrForInvalidLocation)
{
    // Arrange
    Toy toy(toyHeight, toyWidth);
    toy.addCell(cell1);

    // Act
    cell* result = toy.getCellInDir(cell1Loc, dir::EAST);

    // Assert
    EXPECT_EQ(nullptr, result);
}

TEST_F(ToyTest, countNeighbors_returnsCorrectCount)
{
    // Arrange
    Toy toy(toyHeight, toyWidth);
    toy.addCell(cell1);
    toy.addCell(cell2);
    toy.addCell(cell3);

    // Act
    int result = toy.countNeighbors(cell2);

    // Assert
    EXPECT_EQ(1, result);
}

TEST_F(ToyTest, computeSurfaceArea_returnsCorrectSurfaceArea)
{
    // Arrange
    Toy toy(toyHeight, toyWidth);
    toy.addCell(cell1);
    toy.addCell(cell2);
    toy.addCell(cell3);

    // Act
    int result = toy.computeSurfaceArea();

    // Assert
    EXPECT_EQ(14, result);
}


TEST(TestSurfaceArea, BasePlate3 ) {
    
    int res = surfaceArea({{1,3,4},{2,2,3},{1,2,4}});
    EXPECT_EQ(60, res);
}