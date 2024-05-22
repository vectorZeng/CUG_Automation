function cost_matrix = get_input()
    % 读取用户输入
    fprintf("请输入增广矩阵:（每次输入1行，用空格分隔，输入结束后回车即可）\r\n");
    % 读取矩阵
    cost_matrix = [];
    line = input("", 's');
    while ~isempty(line)
        values = strsplit(line, ' ');
        values = cellfun(@str2num, values);
        cost_matrix = [cost_matrix; values];
        line = input("", 's');
    end
end