#include "ublox_receiver_view.h"
#include "ui_ublox_receiver_view.h"

UbloxReceiverView::UbloxReceiverView(QWidget *parent) : QWidget(parent), ui(new Ui::UbloxReceiverView)
{
    ui->setupUi(this);
}

UbloxReceiverView::~UbloxReceiverView()
{
    delete ui;
}
