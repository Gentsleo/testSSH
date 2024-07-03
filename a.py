def detect_sequence(input_string):
    # Define states
    S0, S1, S2, S3, S4, S5 = 0, 1, 2, 3, 4, 5
    
    # Initial state
    current_state = S0
    
    # Process each character in the input string
    for char in input_string:
        if current_state == S0:
            if char == '1':
                current_state = S1
            # No need to handle '0' because we stay in S0
        elif current_state == S1:
            if char == '0':
                current_state = S2
            elif char == '1':
                current_state = S1
        elif current_state == S2:
            if char == '1':
                current_state = S3
            elif char == '0':
                current_state = S1
        elif current_state == S3:
            if char == '1':
                current_state = S4
            elif char == '0':
                current_state = S2
        elif current_state == S4:
            if char == '0':
                current_state = S5
            elif char == '1':
                current_state = S4
        elif current_state == S5:
            # Sequence detected
            return True
    
    # If we finish the input without reaching S5
    return False

# Example usage:
input_string = "1011110"
result = detect_sequence(input_string)
print("Sequence '10110' detected:" if result else "Sequence '10110' not detected.")