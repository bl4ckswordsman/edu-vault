const imageInput = document.getElementById('imageInput');
const topTextInput = document.getElementById('topTextInput');
const bottomTextInput = document.getElementById('bottomTextInput');
const textSizeInput = document.getElementById('textSizeInput');

const memeImage = document.getElementById('memeImage');
const topTextOutput = document.getElementById('topTextOutput');
const bottomTextOutput = document.getElementById('bottomTextOutput');

function updateMemeText() {
    topTextOutput.innerText = topTextInput.value;
    bottomTextOutput.innerText = bottomTextInput.value;
    const fontSize = textSizeInput.value + 'px';
    topTextOutput.style.fontSize = fontSize;
    bottomTextOutput.style.fontSize = fontSize;
}

topTextInput.addEventListener('input', updateMemeText);
bottomTextInput.addEventListener('input', updateMemeText);
textSizeInput.addEventListener('input', updateMemeText);

updateMemeText();
imageInput.addEventListener('change', function (event) {
    const file = event.target.files[0];
    if (file) {
        const reader = new FileReader();
        reader.onload = function (e) {
            memeImage.src = e.target.result;
            memeImage.classList.add('loaded');
        };
        reader.readAsDataURL(file);
    }
});