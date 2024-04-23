function ToFloat(hex) {
    console.log("TO FLOAT");
    console.log('Hex:', hex);

    let binary = '';
    for (let i = 2; i < hex.length; i++) {
        binary += parseInt(hex[i], 16).toString(2).padStart(4, '0');
    }

    let sign = parseInt(binary[0], 2) === 1 ? '-' : '+';
    let exponent = parseInt(binary.substr(1, 8), 2) - 127;
    let mantissa = binary.substr(9);

    let float = 1; // Initialize with implicit leading 1
    for (let i = 0; i < mantissa.length; i++) {
        float += parseInt(mantissa[i], 2) * Math.pow(2, -i - 1);
    }
    
    if (exponent > 0) {
        for (let i = 0; i < exponent; i++) {
            float *= 2;
        }
    } else {
        for (let i = 0; i < -exponent; i++) {
            float /= 2;
        }
    }

    console.log("Binary:", binary)
/*  console.log('Sign:', sign);
    console.log('Exponent:', exponent);
    console.log('Mantissa:', mantissa); */
    console.log('Float:', float); 
}

function ToHex(float) {
    console.log("TO HEX");
    console.log('Float:', float);

    let floatView = new Float32Array(1);
    floatView[0] = float;
    let intView = new Uint32Array(floatView.buffer);
    
    let hex = intView[0].toString(16).toUpperCase().padStart(8, '0');
    
    let binary = intView[0].toString(2).padStart(32, '0');
    let sign = binary.charAt(0);
    let exponent = binary.substr(1, 8);
    let mantissa = binary.substr(9);
    
    console.log("Binary:", binary)
/*  console.log('Sign:', sign);
    console.log('Exponent:', exponent);
    console.log('Mantissa:', mantissa); */
    console.log('Hex:', ('0x' + hex).toLowerCase());
}

ToFloat('0x45a6ac14');
console.log("----------------------------------------");
ToHex(928.33);