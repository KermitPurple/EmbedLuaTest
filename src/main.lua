function factorial(n) 
    if n < 2 then
        return 1
    end
    return n * factorial(n - 1)
end

nice = 1
