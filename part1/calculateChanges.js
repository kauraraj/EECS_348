document.getElementById('calculateColors').addEventListener('click', function () {
    var borderR = document.getElementById('borderR').value;
    var borderG = document.getElementById('borderG').value;
    var borderB = document.getElementById('borderB').value;
    var borderWidth = document.getElementById('borderWidth').value;
    var backgroundR = document.getElementById('backgroundR').value;
    var backgroundG = document.getElementById('backgroundG').value;
    var backgroundB = document.getElementById('backgroundB').value;

    var colorParagraph = document.getElementById('colorParagraph');
    colorParagraph.style.borderColor = `rgb(${borderR}, ${borderG}, ${borderB})`;
    colorParagraph.style.borderWidth = `${borderWidth}px`;
    colorParagraph.style.backgroundColor = `rgb(${backgroundR}, ${backgroundG}, ${backgroundB})`;
});
