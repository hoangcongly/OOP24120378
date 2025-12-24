def read_graph_from_file(filename):
    """
    Đọc ma trận liên kề từ file và trả về list of lists
    """
    matrix = []
    try:
        with open(filename, 'r') as file:
            for line in file:
                row = [int(val) for val in line.strip().split()]
                matrix.append(row)
    except FileNotFoundError:
        print(f"Loi: Khong tim thay file '{filename}'")
    return matrix


example_matrix = read_graph_from_file('graph_example.txt')
print("Ma tran ke doc tu file:")
for row in example_matrix:
    print(row)
