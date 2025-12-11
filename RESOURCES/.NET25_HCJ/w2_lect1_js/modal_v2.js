const openBtn = document.getElementById("openModalBtn");
const closeBtn = document.getElementById("closeModalBtn");
const modal = document.getElementById("modalOverlay");

function openModal() {
    modal.classList.remove("modal-hidden");
}

function closeModal() {
    modal.classList.add("modal-hidden");
}

openBtn.addEventListener("click", openModal);
closeBtn.addEventListener("click", closeModal);