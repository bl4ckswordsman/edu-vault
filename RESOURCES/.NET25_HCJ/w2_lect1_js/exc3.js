
const duckImages = [
    'resurser/duck1.jpg',
    'resurser/duck2.jpg',
    'resurser/duck3.jpg',
    'resurser/duck4.jpg',
    'resurser/duck5.jpg',
    'resurser/duck6.jpg',
    'resurser/duck7.jpg'
];

const quotesLose = [
    "Inte ens nära...",
    "Bättre lycka nästa gång, kvack!",
    "Ankorna skrattar åt dig."
];

const quotesAlmost = [
    "Sååå nära!",
    "Två av tre är inte illa.",
    "Kom igen, en till!"
];

const quotesWin = [
    "JACKPOT! Kvack kvack!",
    "Du är kungen av dammen!",
    "Vinst! Matdags!"
];

const slot1 = document.getElementById('slot1');
const slot2 = document.getElementById('slot2');
const slot3 = document.getElementById('slot3');
const quoteDisplay = document.getElementById('quoteDisplay');
const spinBtn = document.getElementById('spinBtn');


function spin() {
    const index1 = Math.floor(Math.random() * duckImages.length);
    const index2 = Math.floor(Math.random() * duckImages.length);
    const index3 = Math.floor(Math.random() * duckImages.length);

    slot1.src = duckImages[index1];
    slot2.src = duckImages[index2];
    slot3.src = duckImages[index3];

    checkWin(index1, index2, index3);
}

function checkWin(i1, i2, i3) {
    let quote = "";

    if (i1 === i2 && i2 === i3) {
        quote = getRandomQuote(quotesWin);

    } else if (i1 === i2 || i2 === i3 || i1 === i3) {
        quote = getRandomQuote(quotesAlmost);

    } else {
        quote = getRandomQuote(quotesLose);
    }

    quoteDisplay.innerText = quote;
}

function getRandomQuote(quoteArray) {
    const randomIndex = Math.floor(Math.random() * quoteArray.length);
    return quoteArray[randomIndex];
}

spinBtn.addEventListener('click', spin);