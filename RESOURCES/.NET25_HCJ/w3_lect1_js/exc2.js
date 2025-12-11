const inputArea = document.querySelector('#input-area');
const outputArea = document.querySelector('#output-area');

inputArea.addEventListener('input', () => {

    let htmlContent = inputArea.value;
    const sanitizedContent = htmlContent.replace(/on\w+\s*=\s*["'].*?["']/gi, '');

    outputArea.innerHTML = sanitizedContent;
});