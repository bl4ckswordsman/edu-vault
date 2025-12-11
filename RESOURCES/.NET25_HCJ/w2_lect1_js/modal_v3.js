const openBtn = document.getElementById("openDialogBtn");
const closeBtn = document.getElementById("closeDialogBtn");
const dialog = document.getElementById("myDialog");

openBtn.addEventListener("click", () => {
    dialog.showModal();
});

closeBtn.addEventListener("click", () => {
    dialog.close();
});
