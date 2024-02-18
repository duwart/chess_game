struct Position
{
    int8_t row;
    int8_t column;
    bool isEqual(Position pos)
    {
        return (row == pos.row) && (column == pos.column);
    }
};